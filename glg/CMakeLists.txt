file(GLOB ROOT_INLINE *.inl)
file(GLOB ROOT_HEADER *.hpp)

file(GLOB_RECURSE CORE_INLINE ./*/*.inl)
file(GLOB_RECURSE CORE_HEADER ./*/*.hpp)

source_group("Core Files" FILES ${CORE_INLINE})
source_group("Core Files" FILES ${CORE_HEADER})

add_library(glg INTERFACE)
target_include_directories(glg INTERFACE ../)

if (BUILD_STATIC_LIBS)
    add_library(glg_static STATIC ${ROOT_INLINE} ${ROOT_HEADER} ${CORE_INLINE} ${CORE_HEADER})
    target_link_libraries(glg_static PUBLIC glg)
    add_library(glg::glg_static ALIAS glg_static)
endif ()

if (BUILD_SHARED_LIBS)
    add_library(glg_shared SHARED ${ROOT_INLINE} ${ROOT_HEADER} ${CORE_INLINE} ${CORE_HEADER})
    target_link_libraries(glg_shared PUBLIC glg)
    add_library(glg::glg_shared ALIAS glg_shared)
endif ()
