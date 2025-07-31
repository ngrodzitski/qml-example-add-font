from conan import ConanFile
from conan.errors import ConanInvalidConfiguration
from conan.tools.build import check_min_cppstd
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout
from conan.tools.files import rmdir
from conan.tools.scm import Version
import os, sys, re


class AppWithCustomFontConan(ConanFile):

    def set_version(self):
        version_file_path = os.path.join(
            self.recipe_folder,
            "AppWithCustomFont/include/AppWithCustomFont/version.hpp"
        )
        with open(version_file_path, 'r') as file:
            content = file.read()
            major_match = re.search(r'VERSION_MAJOR\s+(\d+)ull', content)
            minor_match = re.search(r'VERSION_MINOR\s+(\d+)ull', content)
            patch_match = re.search(r'VERSION_PATCH\s+(\d+)ull', content)

            if major_match and minor_match and patch_match:
                major = int(major_match.group(1))
                minor = int(minor_match.group(1))
                patch = int(patch_match.group(1))
                self.version = f"{major}.{minor}.{patch}"
            else:
                raise ValueError(f"cannot detect version from {version_file_path}")

    name = "app_with_custom_font"

    license = "Boost Software License - Version 1.0"
    author = "Nicolai Grodzitski"
    url = "https://github.com/ngrodzitski/qml-example-add-font"
    homepage = "https://github.com/ngrodzitski/qml-example-add-font"
    description = "Demo project to show how to add a custom font to QML application"
    topics = ("AppWithCustomFont", "QML", "Custom Font")

    settings = "os", "compiler", "build_type", "arch"

    no_copy_source = True
    build_policy = "missing"
    _cmake = None

    def requirements(self):
        # TODO: add your libraries here
        self.requires("fmt/[~11]")

    def layout(self):
        cmake_layout(self, src_folder=".", build_folder=".")
        self.folders.generators = ""

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["APP_WITH_CUSTOM_FONT_INSTALL"] = True
        tc.variables["APP_WITH_CUSTOM_FONT_CONAN_BUILD"] = True
        tc.variables[
            "APP_WITH_CUSTOM_FONT_BUILD_TESTS"
        ] = True

        tc.generate()

        cmake_deps = CMakeDeps(self)
        cmake_deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure(build_script_folder=self.source_folder)
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
        rmdir(self, os.path.join(self.package_folder, "lib", "cmake"))
