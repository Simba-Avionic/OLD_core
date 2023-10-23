load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "core",
    visibility = ["//visibility:public"],
    deps = [
        "@core//application:simba_application",
        "@core//common:common_converter",
        "@core//common:common_types",
        "@core//logger:console_logger",
    ],
)

cc_test(
    name = "core_test",
    srcs = ["test/sample_test.cc"],
    deps = ["@com_google_googletest//:gtest_main"],
)

#bazel run :benchmark
cc_binary(
    name = "core_benchmark",
    srcs = ["test/benchmark/sample_benchmark.cc"],
    deps = [
        "@com_google_benchmark//:benchmark_main",
    ],
)
