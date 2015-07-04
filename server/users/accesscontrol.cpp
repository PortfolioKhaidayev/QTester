#include "accesscontrol.h"

AccessControl::AccessControl()
{

}

bool AccessControl::isAccessTo(const User &, const Permissions::Permission , const SQLMgr &)
{
//    QString group = user.getGroup();
//    SqlWhere where(Tables::UserGroups::Fields::NAME + " = " + group);
//    db.select( Tables::UserGroups::TABLE_NAME, {Tables::UserGroups::Fields::NAME},  "");
    return false;
}

