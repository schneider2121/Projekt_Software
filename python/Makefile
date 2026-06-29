VENV := .venv
PIP := $(VENV)/bin/pip
PYTEST := $(VENV)/bin/pytest
RUFF := $(VENV)/bin/ruff

.PHONY: setup test check clean

$(VENV)/bin/activate:
	python3 -m venv $(VENV)
	$(PIP) install --upgrade pip
	$(PIP) install pytest ruff

setup: $(VENV)/bin/activate

test: setup
	$(PYTEST) test/ -v

check: setup
	$(RUFF) check src/ test/

clean:
	rm -rf $(VENV) **/__pycache__ .pytest_cache .ruff_cache