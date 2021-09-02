file1 = open('./raw_output.txt', 'r')
Lines = file1.readlines()
 
cla = -1
finding = -1
ending = -1
search = []
for linenumber, line in enumerate(Lines):
    if "CLA ./" in line:
        cla=linenumber
    elif "CLA.py ./" in line:
        cla=linenumber
    if cla != -1:
        if "yyParse returns SYNTAX error in the input file" in line:
            finding = linenumber
            ending = linenumber + 1
        elif "Aborted" in line:
            finding = linenumber
            ending = linenumber + 1
    
    print("Line {}: {}".format(linenumber, line.rstrip()))

    if ending != -1:
        search.append({'cla': cla, 'finding': finding, 'ending': ending})

        cla = -1
        finding = -1
        ending = -1

i=0
cla_line=""
errors=""

for linenumber, line in enumerate(Lines):
    if i < len(search):
        if linenumber >= search[i]["cla"] and linenumber <= search[i]["ending"]:
            if linenumber == search[i]["cla"]:
                cla_line = line.strip()
                errors+="\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ >>> start: " + cla_line + "\n"

            errors += "Line {}: {}".format(linenumber, line.rstrip()) + "\n"

            if linenumber == search[i]["ending"]:
                errors += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ <<< end: " + cla_line + "\n"
                i+=1

if len(search) > 0:
    errors += "\nTotal error: " + str(len(search))

print(errors)
print(search)

f = open("./errors.txt", "a")
f.write(errors)
f.close()
