import("./adl.js").then((obj=>{
    hljs.registerLanguage('adl', obj.default)
    hljs.highlightAll();
}))