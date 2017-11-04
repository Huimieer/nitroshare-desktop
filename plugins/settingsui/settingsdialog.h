/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QList>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

class Application;
class Setting;

class SettingWidget;

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:

    explicit SettingsDialog(Application *application);

public slots:

    virtual void accept();

private slots:

    void onSettingAdded(Setting *setting);
    void onSettingRemoved(Setting *setting);

private:

    // Individual setting and associated widget
    struct Item {
        Setting *setting;
        SettingWidget *widget;
    };

    // Individual tab and its associated settings
    struct Tab {
        QString name;
        QWidget *widget;
        QVBoxLayout *layout;
        QList<Item> items;
    };

    Tab &getTab(Setting *setting);
    void createItem(Setting *setting);

    Application *mApplication;

    QTabWidget *mTabWidget;

    QList<Tab> mTabs;
};

#endif // SETTINGSDIALOG_H
