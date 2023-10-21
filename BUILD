load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "core",
    # srcs = [""],
    # hdrs = [""],
    deps = [
        "@core//common:common_types",
        "@core//common:common_converter",
    ],
    visibility = ["//visibility:public"],
)


# cc_test(
#     name = "core_test",
#     srcs = ["test/sample_test.cc"],
#     deps = ["@com_google_googletest//:gtest_main"],
# )

# #bazel run :benchmark
# cc_binary(
#     name = "core_benchmark",
#     srcs = ["test/benchmark/sample_benchmark.cc"],
#     deps = [
#         "@com_google_benchmark//:benchmark_main",
#     ],
# )
