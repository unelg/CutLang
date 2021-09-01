# highlightjs-adl

![version](https://badgen.net/npm/v/highlightjs-adl)

## Description

ADL - a language grammar for highlightjs

### Static website or simple usage

```html
<script type="text/javascript" src="/path/to/highlight.min.js"></script>
<script type="text/javascript" charset="UTF-8"
  src="/path/to/highlightjs-adl/dist/adl.min.js"></script>
<script type="text/javascript">
  hljs.initHighlightingOnLoad();
</script>
```

### Using directly from the UNPKG CDN

```html
<script type="text/javascript"
  src="https://unpkg.com/highlightjs-adl@0.0.1/dist/adl.min.js"></script>
```

- More info: <https://unpkg.com>

### With Node or another build system

If you're using Node / Webpack / Rollup / Browserify, etc, simply require the language module, then register it with Highlight.js.

```javascript
var hljs = require('highlightjs');
var hljsadl = require('highlightjs-adl');

hljs.registerLanguage("adl", hljsadl);
hljs.initHighlightingOnLoad();
```