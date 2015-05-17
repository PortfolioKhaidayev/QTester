#include <QtCore/QCoreApplication>

#include "sqlitemgr.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QMap<QString,QString> data;		
    //data["fUne"]  = "INTEGER";
    //data["fDue"]  = "INTEGER";
    //data["fTree"] = "INTEGER";
    //data["fQuatro"] = "VARCHAR(20)";

    QString tableName("tt");	// ��� �������, ������� ���
	SQLMgr *db = new SQLiteMgr("", "", "", "");	
									/*path  - ���� ���� ���� ����������� � �������� �����*/
	QSqlQuery q;

 //   db->createTable(tableName, data); // ��� ������� �������
	
 //   for (auto i = 0; i < 4; i++)	// �������� ������
	//{
 //       DataMap data;
 //       data["fUne"]    = QString::number(i);
 //       data["fDue"]    = QString::number(i*2);
 //       data["fTree"]   = QString::number(i*50);
 //       data["fQuatro"] = QString::number(i) + " text";

 //       q = db->insert(tableName, data );
	//}

    q = db->select(tableName, {"*"}); // ������� ��������� ������

									   
    QSqlRecord  rec = q.record(); // ������� ��� ������ � �������
	int			nFUne = 0;	 // ��������������� ����������
	QString		strFDue;
	QString		strFTree;
	QString		strFQuatro;
	  // �������
	int count = 0;
	while (q.next()){
		count++;		// ����� ������� 8 �� ���� �� ���� 10000, �� ��� ��������� ������� ������
	}

	qDebug() << "count(*) >" << count; // ��������� �������


	q.first();		// �� ������ ������ � ������ ������
	//while (q.next()) {	  // ������� ���� ������ �� ����������
	//	
 //       nFUne =		 q.value( 0 ).toInt();
 //       strFDue =	 q.value( 1 ).toString();
 //       strFTree =	 q.value( 2 ).toString();
 //       strFQuatro = q.value( 3 ).toString();

 //       qDebug() << nFUne << "| " << strFDue << "|"
 //           << strFTree << "|" << strFQuatro << "|  next"; // ��������������� ����� ������
	//}
  
    return  /*0;*/ a.exec(); // �� ���� ��� � ���� ���������
}								
