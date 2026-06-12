from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps
from pathlib import Path


class AlciaConan(ConanFile):
    name = "alcia"
    version = Path(__file__).parent.joinpath("VERSION").read_text().strip()
    settings = "os", "compiler", "build_type", "arch"
    options  = {
        "with_tests":      [True, False],
        "with_benchmarks": [True, False],
    }
    default_options = {
        "with_tests":      True,
        "with_benchmarks": False,
    }

    def requirements(self):
        if self.options.with_tests:
            self.requires("gtest/1.15.0")
        if self.options.with_benchmarks:
            self.requires("benchmark/1.8.4")

    def layout(self):
        self.folders.generators = "generators"

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["ALCIA_ENABLE_TESTS"]      = bool(self.options.with_tests)
        tc.variables["ALCIA_ENABLE_BENCHMARKS"] = bool(self.options.with_benchmarks)
        tc.generate()
        CMakeDeps(self).generate()
