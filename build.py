# /// script
# dependencies = ["markdown"]
# ///

from pathlib import Path
import shutil
import markdown

DEV_DIR = Path(__file__).resolve().parent.parent / "syscross_dev"
TARGET_DIR = DEV_DIR / ".target"

HTML_TEMPLATE = """<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>SysCross</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/5.8.1/github-markdown.min.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Noto+Sans+Mono:wght@400;700&display=swap" rel="stylesheet">
    <style>
        body {
            margin: 0;
            background-color: #ffffff;
        }
        @media (prefers-color-scheme: dark) {
            body { background-color: #0d1117; }
        }
        .markdown-body, .markdown-body pre, .markdown-body code, .markdown-body tt {
            font-family: "Noto Sans Mono CJK JP", "Noto Sans Mono", ui-monospace, SFMono-Regular, Menlo, Consolas, monospace;
        }
        .markdown-body {
            box-sizing: border-box;
            min-width: 200px;
            max-width: 980px;
            margin: 0 auto;
            padding: 45px;
        }
        @media (max-width: 767px) {
            .markdown-body { padding: 15px; }
        }
    </style>
</head>
<body class="markdown-body">
{body}
</body>
</html>
"""


def build() -> None:
    if TARGET_DIR.exists():
        shutil.rmtree(TARGET_DIR)
    TARGET_DIR.mkdir(parents=True, exist_ok=True)

    for md_path in DEV_DIR.rglob("*.md"):
        rel = md_path.relative_to(DEV_DIR)
        if any(part.startswith(".") for part in rel.parts):
            continue

        out_rel = rel.with_name("index.html") if rel.name.lower() == "readme.md" else rel.with_suffix(".html")
        out_path = TARGET_DIR / out_rel
        out_path.parent.mkdir(parents=True, exist_ok=True)

        body = markdown.markdown(md_path.read_text(encoding="utf-8"), extensions=["extra"])
        out_path.write_text(HTML_TEMPLATE.replace("{body}", body), encoding="utf-8")
        print(f"{rel} -> .target/{out_rel}")


if __name__ == "__main__":
    build()
