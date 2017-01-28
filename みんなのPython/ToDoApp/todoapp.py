from datetime import datetime
from pickle import dump, load
from tkinter import *
import tkinter.messagebox
from todoitem import ToDoItem
from todocontainer import ToDoContainer

DUMPFILE = 'todo.dat'

class ToDoApp(Frame):
    """
    ToDo GUIアプリ用のクラス
    """

    def createwidgets(self):
        """
        ボタンなどウィンドウの部品を作る
        """
        # スクロールバー付きリフトボックス
        self.frame1 = Frame(self)
        frame = self.frame1

        self.listbox = Listbox(frame, height=10, width=30, selectmode=SINGLE, takefocus=1)
        self.yscroll = Scrollbar(frame, orient=VERTICAL)

        # 配置を決める
        self.listbox.grid(row=0, column=0, sticky=NS)
        self.yscroll.grid(row=0, column=1, sticky=NS)

        # 動きとコードをつなげる
        self.yscroll.config(command=self.listbox.yview)
        self.listbox.config(yscrollcommand=self.yscroll.set)
        self.listbox.bind("<ButtonRelease-1>", self.selectitem)

        self.frame1.grid(row=0, column=0)

    def setlistitems(self):
        """
        ToDoのうち未消化分をリストに表示する
        """
        self.listbox.delete(0, END)
        for todo in self.todos.get_remaining_todos():
            d = todo.duedate
            t = todo.title.ljust(20)
            if todo.duedate < datetime.now():
                t = '*' + t
            item = "{}  {:4}/{:2}/{:2} {:2}{;2}".format(t, d.year, d.month, d.day, d.hour, d.minute)
            self.listbox.insert(END, item)

    def refrectentries(self, todo):
        """
        フィールドに入力された文字列をToDoItemインスタンスに反映する
        """
        todo.title = self.title_e.get()
        todo.description = self.description_e.get()
        dt = datetime.strptime(self.duedate_e.get()+':oo', '%Y/%m/%d %H:%M:%S')
        todo.duetime = dt

