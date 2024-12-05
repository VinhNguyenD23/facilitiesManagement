cmake_minimum_required(VERSION 3.16)

project(Main VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.7.3/mingw_64/lib/cmake")
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Qt6Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/main.cpp
        src/view/mainwindow.cpp
        src/view/mainwindow.h
        src/view/mainwindow.ui
        src/view/invoicedetailwindow.h
        src/view/invoicedetailwindow.cpp
        src/view/invoicedetailwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Main
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/datatype/Avl.h src/datatype/Avl.cpp
        src/datatype/DynamicArray.h src/datatype/DynamicArray.cpp
        src/datatype/LinkedList.h src/datatype/LinkedList.cpp
        src/controller/FacilityController.h src/controller/FacilityController.cpp
        src/controller/InvoiceController.h src/controller/InvoiceController.cpp
        src/controller/InvoiceDetailController.h src/controller/InvoiceDetailController.cpp
        src/controller/StaffController.h src/controller/StaffController.cpp
        src/controller/StatisticController.h src/controller/StatisticController.cpp
        src/model/Facilities.h src/model/Facilities.cpp
        src/model/InvoiceDetail.h src/model/InvoiceDetail.cpp
        src/model/Invoices.h src/model/Invoices.cpp
        src/model/Staffs.h src/model/Staffs.cpp
        src/model/GlobalModel.h src/model/GlobalModel.cpp
        src/object/Facility.h
        src/object/Invoice.h
        src/object/InvoiceDetail.h
        src/object/Staff.h
        src/object/Date.h
        src/service/FacilityService.h src/service/FacilityService.cpp
        src/service/InvoiceDetailService.h src/service/InvoiceDetailService.cpp
        src/service/InvoiceService.cpp src/service/InvoiceService.h
        src/service/StaffService.cpp src/service/StaffService.h
        src/service/StatisticService.h src/service/StatisticService.cpp
        src/exception/DatabasesException.h 
	src/exception/DataException.h
        src/util/StringUtil.h
        src/resource.qrc
        src/util/ArrayUtil.h
        src/exception/ValidateException.h

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Main APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Main SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Main
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Main PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Main)
endif()
set_target_properties(Main PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Main
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Main)
endif()
