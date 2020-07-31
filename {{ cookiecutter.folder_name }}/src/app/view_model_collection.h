//
// Copyright (c) {{ cookiecutter.year }}, {{ cookiecutter.who_am_I }} ({{ cookiecutter.email }})
// See LICENSE.txt
//
// {{ cookiecutter.website }}
//
#ifndef PROJECT_APP_VIEW_MODEL_COLLECTION_H
#define PROJECT_APP_VIEW_MODEL_COLLECTION_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>

#include <memory>

{% set nslist = cookiecutter.cpp_namespace.split('::') %}
{% for ns in nslist %}
namespace {{ ns }}
{
{% endfor %}
class CliOptions;
class EventFilter;
class GuiTests;
class LoggingTags;
class QmlMessageInterceptor;

class ViewModelCollection
{
public:
    explicit ViewModelCollection( const QGuiApplication& app );
    ~ViewModelCollection();

    ViewModelCollection( const ViewModelCollection& ) = delete;
    ViewModelCollection& operator=( const ViewModelCollection& ) = delete;

    void ExportContextPropertiesToQml( QQmlApplicationEngine* engine );

    void SetRootObject( QObject* object );

private:
    const std::unique_ptr<const CliOptions> m_opts;
    std::unique_ptr<EventFilter> m_eventFilter;
    std::unique_ptr<QmlMessageInterceptor> m_qmlLogger;
    std::unique_ptr<LoggingTags> m_logging;

    std::unique_ptr<GuiTests> m_guiTests;
};
{% for ns in nslist %}
} // namespace {{ ns }}
{% endfor %}

#endif // PROJECT_APP_VIEW_MODEL_COLLECTION_H
