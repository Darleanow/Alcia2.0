#!/usr/bin/env python3
"""Patch a Doxygen-generated header.html for doxygen-awesome-css."""
import pathlib, re, sys

header = pathlib.Path(sys.argv[1] if len(sys.argv) > 1 else "docs/doxygen/header.html")
txt = header.read_text()

txt = re.sub(r"<body>", '<body class="doxygen-awesome-css">', txt)

scripts = (
    '  <script src="$relpath^doxygen-awesome-darkmode-toggle.js"></script>\n'
    '  <script src="$relpath^doxygen-awesome-fragment-copy-button.js"></script>\n'
    '  <script src="$relpath^doxygen-awesome-paragraph-link.js"></script>\n'
    '  <script src="$relpath^doxygen-awesome-interactive-toc.js"></script>\n'
    "  <script>\n"
    "    document.addEventListener('DOMContentLoaded', function() {\n"
    "      DoxygenAwesomeDarkModeToggle.init();\n"
    "      DoxygenAwesomeFragmentCopyButton.init();\n"
    "      DoxygenAwesomeParagraphLink.init();\n"
    "      DoxygenAwesomeInteractiveToc.init();\n"
    "    });\n"
    "  </script>\n"
    "</head>"
)
txt = txt.replace("</head>", scripts)

header.write_text(txt)
