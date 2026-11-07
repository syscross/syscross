# /// script
# dependencies = ["markdown", "pymdown-extensions"]
# ///

from pathlib import Path
import subprocess
import sys
from build import build

ROOT_DIR = Path(__file__).resolve().parent


def publish() -> None:
    build()
    subprocess.run(["sh", "sync_dev.sh", *sys.argv[1:]], cwd=ROOT_DIR, check=True)


if __name__ == "__main__":
    publish()
