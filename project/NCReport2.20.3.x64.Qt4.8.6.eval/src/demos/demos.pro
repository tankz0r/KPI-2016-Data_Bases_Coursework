SUBDIRS += \
    CustomDataSource \
    CustomItem \
    ItemModelDataSource \
    StringListDataSource \
    StringParameterDataSource \
    SimpleDemoApp \
    GraphDemo \
    SqlGraphDemo \
    ItemModelRelationDemo \
    PreviewWidgetTest

contains(EXTENSIONS, designerlib): SUBDIRS += RunDesignerFromApp

TEMPLATE = subdirs
