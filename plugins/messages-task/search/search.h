#ifndef SEARCH_H
#define SEARCH_H

#include <QObject>
#include <QGSettings>
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <SwitchButton/switchbutton.h>
#include <QGSettings>
#include "HoverWidget/hoverwidget.h"
#include "shell/interface.h"
#include "ComboxFrame/comboxframe.h"

#define UKUI_SEARCH_SCHEMAS "org.ukui.search.settings"
#define SEARCH_METHOD_KEY "indexSearch"
#define WEB_ENGINE_KEY "webEngine"
//TODO
#define CONFIG_FILE "..."

namespace Ui {
class Search;
}

class Search : public QObject, CommonInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.kycc.CommonInterface")
    Q_INTERFACES(CommonInterface)

public:
    explicit Search();
    ~Search();

    QString get_plugin_name()   Q_DECL_OVERRIDE;
    int get_plugin_type()       Q_DECL_OVERRIDE;
    QWidget * get_plugin_ui()   Q_DECL_OVERRIDE;
    void plugin_delay_control() Q_DECL_OVERRIDE;
    const QString name() const  Q_DECL_OVERRIDE;

private:
    Ui::Search *ui;

    QWidget * m_plugin_widget = nullptr;
    QString m_plugin_name = "";
    int m_plugin_type = 0;

    QGSettings * m_gsettings = nullptr;

    void initUi();
    QVBoxLayout * m_mainLyt = nullptr;
    //设置搜索模式
    QLabel * m_methodTitleLabel = nullptr;
    QLabel * m_descLabel = nullptr;
    QFrame * m_searchMethodFrame = nullptr;
    QHBoxLayout * m_searchMethodLyt = nullptr;
    QLabel * m_searchMethodLabel = nullptr;
    SwitchButton * m_searchMethodBtn = nullptr;
    //设置黑名单
    QLabel * m_blockDirTitleLabel = nullptr;
    QLabel * m_blockDirDescLabel = nullptr;
    HoverWidget * m_addBlockDirWidget = nullptr;
    QLabel * m_addBlockDirIcon = nullptr;
    QLabel * m_addBlockDirLabel = nullptr;
    QStringList m_blockDirs;
    void getBlockDirs(QStringList &blockDirs);
    int setBlockDir(const QString &dirPath);
    //设置搜索引擎
    QLabel * m_webEngineLabel = nullptr;
    ComboxFrame * m_webEngineFrame = nullptr;
};

#endif // SEARCH_H
