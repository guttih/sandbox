add_library(People People.cxx Person.cpp Student.cpp)

target_include_directories(People
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )


install(TARGETS People DESTINATION lib)
install(FILES People.h DESTINATION include)