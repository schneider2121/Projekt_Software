# Projekt_Software

CI/CD-Projekt für ein gemischtes C/C++ und Python "Hello World"-Repository,
erstellt im Rahmen der LV Software Quality (FTB-EIT-DU SS26).

## Projektstruktur

Projekt_Software/
├── Makefile                # Haupt-Makefile, orchestriert C- und Python-Teil
├── c/                      # C-Teil: Hello World + Unity-Tests + cppcheck
│   ├── CMakeLists.txt
│   ├── Makefile
│   ├── src/
│   └── test/
├── python/                 # Python-Teil: Hello World + pytest + Ruff
│   ├── Makefile
│   ├── pyproject.toml
│   ├── src/
│   └── test/
└── .github/workflows/      # GitHub Actions CI

## Voraussetzungen

- CMake, ein C-Compiler (z. B. clang/gcc), `cppcheck`
- Python 3.10+
- `make`

## Lokal bauen und testen

Im Projekt-Root:

make build   # baut den C/C++ Teil (CMake-Konfiguration + Kompilierung)
make test    # führt C-Unit-Tests (Unity) und Python-Tests (pytest) aus
make check   # statische Code-Analyse für C (cppcheck) und Python (Ruff)
make clean   # entfernt alle Build-Artefakte


Die Targets rufen intern die jeweiligen Unterordner (`c/`, `python/`) auf.
Der Python-Teil legt dabei automatisch ein virtuelles Environment (`.venv`)
an und installiert die benötigten Abhängigkeiten (`pytest`, `ruff`).

## C/C++ Teil

- Build-System: **CMake**, Test-Framework: **Unity** (eingebunden via
  `FetchContent`, kein manuelles Vorinstallieren nötig)
- Statische Analyse: **cppcheck**

## Python Teil

- Tests: **pytest**
- Linting: **Ruff** (Konfiguration in `python/pyproject.toml`)

## Continuous Integration

Bei jedem Push auf `main` und bei jedem Pull Request laufen automatisch
zwei parallele GitHub-Actions-Jobs:

1. **C/C++ Build & Test** – Build, Unit-Tests, statische Analyse
2. **Python Test & Lint** – Unit-Tests, statische Analyse

Der Workflow ist unter `.github/workflows/ci.yml` definiert.

## Branch Protection

Der `main`-Branch ist geschützt:
- keine direkten Pushes (auch nicht für Admins)
- Merges nur über Pull Requests
- beide CI-Checks müssen erfolgreich sein, bevor gemergt werden kann