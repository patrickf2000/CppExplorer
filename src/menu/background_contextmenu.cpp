//
// Copyright 2021 Patrick Flynn
// This file is part of Odyssey file explorer.
// Odyssey is licensed under the BSD-3 license. See the COPYING file for more information.
//
#include <QPixmap>

#include <menu/background_contextmenu.hpp>
#include <clipboard.hpp>
#include <actions.hpp>

BackgroundContextMenu::BackgroundContextMenu(BrowserWidget *b) {
    bWidget = b;

    newFolder = new QAction(QPixmap(":/icons/folder-new.svg"), "New Folder", this);
    newFile = new QAction(QPixmap(":/icons/document-new.svg"), "New File", this);
    paste = new QAction(QPixmap(":/icons/edit-paste.svg"), "Paste", this);

    connect(newFolder, &QAction::triggered, this, &BackgroundContextMenu::onNewFolderClicked);
    connect(newFile, &QAction::triggered, this, &BackgroundContextMenu::onNewFileClicked);
    connect(paste, &QAction::triggered, this, &BackgroundContextMenu::onPasteClicked);

    this->addAction(newFolder);
    this->addAction(newFile);
    this->addSeparator();
    this->addAction(paste);
}

BackgroundContextMenu::~BackgroundContextMenu() {
    delete newFolder;
    delete newFile;
    delete paste;
}

void BackgroundContextMenu::onNewFolderClicked() {
    Actions::newFolder();
}

void BackgroundContextMenu::onNewFileClicked() {
    Actions::newFile();
}

void BackgroundContextMenu::onPasteClicked() {
    clipboard.newPath = bWidget->fsCurrentPath();
    Actions::paste();
}

