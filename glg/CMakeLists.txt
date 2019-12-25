file(GLOB_RECURSE SOURCE_FILES */*.hpp */*.inl)

add_library(glg INTERFACE)
target_include_directories(glg INTERFACE ../)