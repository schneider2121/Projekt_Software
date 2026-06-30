import sys
from pathlib import Path

# damit "src" importierbar ist, ohne ein Package zu installieren
sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "src"))

from hello import get_greeting


def test_get_greeting_returns_hello_world():
    assert get_greeting() == "Hello, World!"