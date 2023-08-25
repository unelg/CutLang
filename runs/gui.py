import ROOT
import sys
import tkinter as tk
import tempfile
from tkinter import filedialog, scrolledtext, Listbox, Button, Entry, Label, Checkbutton,Text, ttk, IntVar
from io import StringIO
import subprocess
import os

class CutLangInterface(tk.Frame):
    def __init__(self, parent):
        tk.Frame.__init__(self, parent)
        self.pack(fill=tk.BOTH, expand=True)

        self.filelist_label = Label(self, text="Files for FileList:")
        self.filelist_label.pack(pady=10)

        self.filelist_box = Listbox(self)
        self.filelist_box.pack(pady=10)

        self.browse_button = Button(self, text="Add to FileList", command=self.add_to_filelist)
        self.browse_button.pack(pady=10)

        self.clear_button = Button(self, text="Clear FileList", command=self.clear_filelist)
        self.clear_button.pack(pady=10)

        
        self.adl_label = Label(self, text="Select ADL file:")
        self.adl_label.pack(pady=10)

        self.adl_entry = Entry(self, width=50)
        self.adl_entry.pack(pady=10)

        self.browse_adl_button = Button(self, text="Browse ADL", command=self.browse_adl)
        self.browse_adl_button.pack(pady=10)
        
        self.framework_label = Label(self, text="Input Framework:")
        self.framework_label.pack(pady=10)

        self.framework_entry = Entry(self, width=50)
        self.framework_entry.pack(pady=10)


        self.option_label = Label(self, text="Additional options for CLA:")
        self.option_label.pack(pady=10)

        self.option_entry = Entry(self, width=50)
        self.option_entry.pack(pady=10)

        self.execute_button = Button(self, text="Execute CLA", command=self.execute_cla)
        self.execute_button.pack(pady=20)

    def add_to_filelist(self):
        file_path = filedialog.askopenfilename()
        if file_path:
            self.filelist_box.insert(tk.END, file_path)

    def clear_filelist(self):
        self.filelist_box.delete(0, tk.END)

    def browse_adl(self):
        adl_path = filedialog.askopenfilename(filetypes=[("ADL Files", "*.adl")])
        self.adl_entry.delete(0, tk.END)
        self.adl_entry.insert(0, adl_path)

    def execute_cla(self):
        # Create a unique temporary filename starting with "filelist".
        temp_file = tempfile.NamedTemporaryFile(delete=False, prefix="filelist", suffix=".txt", dir=".")
        temp_filename = temp_file.name

        # Write the file list to the temporary file.
        with open(temp_filename, "w") as f:
            for item in self.filelist_box.get(0, tk.END):
                f.write(f"{item}\n")
                
        framework = self.framework_entry.get()
        adl_path = self.adl_entry.get()
        options = self.option_entry.get()

        command = f"CLA {temp_filename} {framework} -i {adl_path} {options}"
        subprocess.run(command, shell=True) # Ideally, you'd want to capture and display output too.

        # Remove the temporary file after command execution
        os.remove(temp_filename)
# [Here comes the RootFileBrowser definition, exactly as it was before]


class RootFileBrowser:
    def __init__(self, parent):
        self.parent = parent
        self.file_label = tk.Label(self.parent, text="Selected ROOT File:")
        self.file_label.pack()

        self.file_text = tk.Text(self.parent, height=1, width=40)
        self.file_text.pack()

        self.browse_button = tk.Button(self.parent, text="Browse", command=self.browse_file)
        self.browse_button.pack()

        self.histograms_label = tk.Label(self.parent, text="Available Histograms:")
        self.histograms_label.pack()

        self.histogram_listbox = Listbox(self.parent, selectmode=tk.SINGLE)
        self.histogram_listbox.pack()

        self.show_histogram_button = Button(self.parent, text="Show Histogram", command=self.show_histogram)
        self.show_histogram_button.pack()

        self.terminal_label = tk.Label(self.parent, text="ROOT Terminal:")
        self.terminal_label.pack()

        self.terminal = scrolledtext.ScrolledText(self.parent, height=10, width=80)
        self.terminal.pack()

        self.command_label = tk.Label(self.parent, text="Enter ROOT Command:")
        self.command_label.pack()

        self.command_entry = Entry(self.parent, width=80)
        self.command_entry.pack()

        self.execute_button = tk.Button(self.parent, text="Execute", command=self.execute_command)
        self.execute_button.pack()

        # Initialize the list to store TCanvas objects and the current ROOT file
        self.canvases = []
        self.current_file = None


    def close_current_file(self):
        """Close the current ROOT file and clear the list of canvases."""
        if self.current_file and not self.current_file.IsZombie():
            self.current_file.Close()
            self.current_file = None
        self.canvases = []

    def browse_file(self):
        print("Browsing for ROOT file...")  # Debugging print statement
        file_path = filedialog.askopenfilename(filetypes=[("ROOT Files", "*.root")])
        if file_path:
            self.file_text.delete(1.0, tk.END)
            self.file_text.insert(tk.END, file_path)
            self.populate_histogram_list(file_path)

    def populate_histogram_list(self, filename):
        print(f"Populating histogram list for file: {filename}")  # Debugging print statement
        self.close_current_file()
        
        f = ROOT.TFile(filename, "READ")
        if not f or f.IsZombie():
            print("Error opening the ROOT file.")
            return

        self.histogram_listbox.delete(0, tk.END)
        
        def extract_histograms_from_directory(directory, path=""):
            for key in directory.GetListOfKeys():
                obj = key.ReadObj()
                if isinstance(obj, ROOT.TH1):
                    full_path = os.path.join(path, obj.GetName())
                    print(f"Found histogram: {full_path}")  # Debugging print statement
                    self.histogram_listbox.insert(tk.END, full_path)
                elif isinstance(obj, ROOT.TDirectoryFile):
                    new_path = os.path.join(path, obj.GetName())
                    print(f"Entering directory: {new_path}")  # Debugging print statement
                    extract_histograms_from_directory(obj, new_path)
                else:
                    print(f"Found non-histogram object: {obj.GetName()} of type {type(obj)}")  # Debugging print statement
        
        extract_histograms_from_directory(f)
        self.current_file = f

    def show_histogram(self):
        selected_histogram_path = self.histogram_listbox.get(tk.ACTIVE)

        if not self.current_file or not selected_histogram_path:
            self.terminal.insert(tk.END, "No ROOT file or histogram selected.\n")
            return

        histogram = self.current_file.Get(selected_histogram_path)
        if histogram:
            # Clone the histogram so it remains in memory
            cloned_histogram = histogram.Clone()

            # Create a new TCanvas object
            canvas_name = f"canvas_{selected_histogram_path.replace('/', '_')}_{len(self.canvases)}"
            canvas = ROOT.TCanvas(canvas_name, "Histogram Canvas")
            cloned_histogram.Draw()
            canvas.Draw()

            # Store the cloned histogram and canvas in a list
            self.canvases.append({
                'histogram': cloned_histogram,
                'canvas': canvas
            })
        else:
            self.terminal.insert(tk.END, f"Histogram {selected_histogram_path} not found.\n")


    def execute_command(self):
        command = self.command_entry.get()
        if command:
            result = None
            try:
                result = ROOT.gROOT.ProcessLine(command)
            except Exception as e:
                self.terminal.insert(tk.END, f"Error executing command: {e}\n")
                
            if result is not None:
                self.terminal.insert(tk.END, f">>> {command}\n")
                if result == 0:
                    self.terminal.insert(tk.END, "Invalid command.\n")
                else:
                    self.terminal.insert(tk.END, f"Result: {result}\n")
            self.command_entry.delete(0, tk.END)

    def on_closing(self):
        """Handle the window close event to close the ROOT file properly."""
        self.close_current_file()
        self.parent.destroy()
        

    def close_current_file(self):
        """Close the current ROOT file and clear the list of canvases."""
        if self.current_file and not self.current_file.IsZombie():
            self.current_file.Close()
            self.current_file = None
        self.canvases = []

    def browse_file(self):
        print("Browsing for ROOT file...")  # Debugging print statement
        file_path = filedialog.askopenfilename(filetypes=[("ROOT Files", "*.root")])
        if file_path:
            self.file_text.delete(1.0, tk.END)
            self.file_text.insert(tk.END, file_path)
            self.populate_histogram_list(file_path)

    def populate_histogram_list(self, filename):
        print(f"Populating histogram list for file: {filename}")  # Debugging print statement
        self.close_current_file()
        
        f = ROOT.TFile(filename, "READ")
        if not f or f.IsZombie():
            print("Error opening the ROOT file.")
            return

        self.histogram_listbox.delete(0, tk.END)
        
        def extract_histograms_from_directory(directory, path=""):
            for key in directory.GetListOfKeys():
                obj = key.ReadObj()
                if isinstance(obj, ROOT.TH1):
                    full_path = os.path.join(path, obj.GetName())
                    print(f"Found histogram: {full_path}")  # Debugging print statement
                    self.histogram_listbox.insert(tk.END, full_path)
                elif isinstance(obj, ROOT.TDirectoryFile):
                    new_path = os.path.join(path, obj.GetName())
                    print(f"Entering directory: {new_path}")  # Debugging print statement
                    extract_histograms_from_directory(obj, new_path)
                else:
                    print(f"Found non-histogram object: {obj.GetName()} of type {type(obj)}")  # Debugging print statement
        
        extract_histograms_from_directory(f)
        self.current_file = f


    def execute_command(self):
        command = self.command_entry.get()
        if command:
            result = None
            try:
                result = ROOT.gROOT.ProcessLine(command)
            except Exception as e:
                self.terminal.insert(tk.END, f"Error executing command: {e}\n")
                
            if result is not None:
                self.terminal.insert(tk.END, f">>> {command}\n")
                if result == 0:
                    self.terminal.insert(tk.END, "Invalid command.\n")
                else:
                    self.terminal.insert(tk.END, f"Result: {result}\n")
            self.command_entry.delete(0, tk.END)

    def on_closing(self):
        """Handle the window close event to close the ROOT file properly."""
        self.close_current_file()
        self.parent.destroy()
        
        
class MainApp(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("CutLang Tool")
        self.geometry("800x800")

        # Create a tabbed interface
        self.tab_parent = ttk.Notebook(self)

        self.cutlang_tab = ttk.Frame(self.tab_parent)
        self.histogram_tab = ttk.Frame(self.tab_parent)

        self.tab_parent.add(self.cutlang_tab, text="CutLang")
        self.tab_parent.add(self.histogram_tab, text="Histogram Viewer")

        self.tab_parent.pack(expand=1, fill='both')

        # Initialize the CutLang and Histogram Viewers inside their respective tabs
        self.cutlang_interface = CutLangInterface(self.cutlang_tab)
        self.histogram_viewer = RootFileBrowser(self.histogram_tab)

       

if __name__ == "__main__":
    app = MainApp()
    app.mainloop()        
