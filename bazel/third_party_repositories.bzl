load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

def include_spdlog():

    http_archive(
        name = "com_github_fmtlib_fmt",
        sha256 = "3c2e73019178ad72b0614a3124f25de454b9ca3a1afe81d5447b8d3cbdb6d322",
        strip_prefix = "fmt-10.1.1",
        urls = ["https://github.com/fmtlib/fmt/archive/refs/tags/10.1.1.zip"],
        build_file = "@core//bazel:fmtlib.BUILD",
    )

    http_archive(
        name = "com_github_gabime_spdlog",
        build_file = "@core//bazel:spdlog.BUILD",
        sha256 = "6174bf8885287422a6c6a0312eb8a30e8d22bcfcee7c48a6d02d1835d7769232",
        strip_prefix = "spdlog-1.12.0",
        urls = ["https://github.com/gabime/spdlog/archive/refs/tags/v1.12.0.zip"],
    )

    http_archive(
        name = "com_json",
        # build_file = "@core//bazel:spdlog.BUILD",
        # sha256 = "95651d7d1fcf2e5c3163c3d37df6d6b3e9e5027299e6bd050d157322ceda9ac9",
        strip_prefix = "json-develop",
        urls = ["https://github.com/nlohmann/json/archive/refs/heads/develop.zip"],
    )