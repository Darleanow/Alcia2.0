.PHONY: all debug release asan tsan msan coverage tidy cppcheck iwyu lint format bench watch docs fuzz package test run clean distclean help

PRESET ?= debug
SCALE  ?= 2

all: debug

debug release asan tsan msan tidy cppcheck iwyu bench docs fuzz package:
	bash scripts/build.sh $@

coverage:
	bash scripts/build.sh coverage
	cmake --build build/coverage --target coverage --parallel

bench:
	bash scripts/bench.sh

watch:
	bash scripts/watch.sh $(PRESET)

lint:
	bash scripts/lint.sh

format:
	find src include tests -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i

test:
	ctest --preset $(PRESET) --output-on-failure -j$$(nproc)

run:
	QT_SCALE_FACTOR=$(SCALE) bash scripts/run.sh $(PRESET)

clean:
	rm -rf build/$(PRESET)

distclean:
	rm -rf build install CMakeUserPresets.json compile_commands.json

help:
	@echo "Targets : debug | release | asan | tsan | msan | coverage | tidy | cppcheck | iwyu | bench | lint | format | watch | docs | fuzz | package"
	@echo "          test [PRESET=debug] | run [PRESET=debug] [SCALE=2] | watch [PRESET=debug]"
	@echo "          clean [PRESET=debug] | distclean"
	@echo ""
	@echo "Examples: make watch   make run SCALE=1.5   make test PRESET=asan   make bench   make lint"
