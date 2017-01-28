from datetime import datetime, timedelta


class ToDoItem(object):
    """
    ToDo項目を保存するためのクラス
    """

    def __init__(self, title, description, duedate, addeddate=None):
        """
        ToDo項目インスタンスを初期化する
        :param title: タイトル
        :param dedcription: 解説
        :param duedate: 締切日
        :param addeddate: 追加日
        """
        if not addeddate:
            addeddate = datetime.now()
        self.title = title
        self.description = description
        self.duedate = duedate
        self.addeddate = addeddate
        self.finished = False
        self.finisheddate = None

    def finish(self, date=None):
        """
        ToDo項目を終了する
        :param date: 終了日
        :return:
        """
        self.finished = True
        if not date:
            date = datetime.now()
        self.finisheddate = date

    def __repr__(self):
        """
        ToDo項目の表示文字列を作る
        """
        return "<ToDoItem {}, {}>".format(self.title, self.duedate.strftime('%Y/%m/%d %H:%M'))
