from typing import Text
from PyQt5.QtGui import QFont, QIcon
from PyQt5.QtWidgets import *
import sys
from PyQt5.QtPrintSupport import *


class Text_Editor(QMainWindow):
    def __init__(self):
        super(Text_Editor, self).__init__()
        self.editor = QTextEdit()
        self.editor.setFontPointSize(21)
        self.setCentralWidget(self.editor)
        self.font_size_box = QSpinBox()
        self.showMaximized()
        self.setWindowTitle("Text Editor")
        self.create_toolbar()
        self.create_menu_bar()

    def create_menu_bar(self):
        menu_bar = QMenuBar()
        file_menu = QMenu("File", self)
        menu_bar.addMenu(file_menu)

        save_as_pdf_action = QAction("Save as PDF", self)
        save_as_pdf_action.triggered.connect(self.save_as_pdf)
        file_menu.addAction(save_as_pdf_action)

        self.setMenuBar(menu_bar)

    def create_toolbar(self):

        tool_bar = QToolBar()
        undo_action = QAction(QIcon("undo.png"), "undo", self)
        undo_action.triggered.connect(self.editor.undo)
        tool_bar.addAction(undo_action)
        self.addToolBar(tool_bar)

        redo_action = QAction(QIcon("redo.png"), "redo", self)
        redo_action.triggered.connect(self.editor.redo)
        tool_bar.addAction(redo_action)

        tool_bar.addSeparator()
        tool_bar.addSeparator()

        cut_action = QAction(QIcon("cut.png"), "cut", self)
        cut_action.triggered.connect(self.editor.cut)
        tool_bar.addAction(cut_action)

        copy_action = QAction(QIcon("copy.png"), "copy", self)
        copy_action.triggered.connect(self.editor.copy)
        tool_bar.addAction(copy_action)

        paste_action = QAction(QIcon("paste.png"), "paste", self)
        paste_action.triggered.connect(self.editor.paste)
        tool_bar.addAction(paste_action)

        tool_bar.addSeparator()
        tool_bar.addSeparator()

        self.font_size_box.setValue(20)
        self.font_size_box.valueChanged.connect(self.set_font_size)
        tool_bar.addWidget(self.font_size_box)

        tool_bar.addSeparator()

        # bold
        bold_action = QAction(QIcon("bold.png"), 'Bold', self)
        bold_action.triggered.connect(self.bold_text)
        tool_bar.addAction(bold_action)

        underline_action = QAction(QIcon("underline.png"), 'Underline', self)
        underline_action.triggered.connect(self.underline_text)
        tool_bar.addAction(underline_action)

        italic_action = QAction(QIcon("italic.png"), 'Italic', self)
        italic_action.triggered.connect(self.italic_text)
        tool_bar.addAction(italic_action)

        # separator
        tool_bar.addSeparator()

    def italic_text(self):
        state = self.editor.fontItalic()
        self.editor.setFontItalic(not(state))

    def underline_text(self):
        state = self.editor.fontUnderline()
        self.editor.setFontUnderline(not(state))

    def bold_text(self):
        if self.editor.fontWeight() != QFont.Bold:
            self.editor.setFontWeight(QFont.Bold)
            return
        self.editor.setFontWeight(QFont.Normal)

    def set_font_size(self):
        value = self.font_size_box.value()
        self.editor.setFontPointSize(value)

    def save_as_pdf(self):
        file_path, _ = QFileDialog.getSaveFileName(
            self, "Export PDF", None, "PDF Files (*.pdf)")
        printer = QPrinter(QPrinter.HighResolution)
        printer.setOutputFormat(QPrinter.PdfFormat)
        printer.setOutputFileName(file_path)
        self.editor.document().print_(printer)


app = QApplication(sys.argv)
window = Text_Editor()
window.show()
sys.exit(app.exec_())
