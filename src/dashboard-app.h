/*
 * Copyright (C) 2018 George Kiagiadakis <gkiagia@tolabaki.gr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _DASHBOARD_APP_H_
#define _DASHBOARD_APP_H_

#include <gtk/gtk.h>

#define DASHBOARD_TYPE_APP dashboard_app_get_type ()
G_DECLARE_FINAL_TYPE (DashboardApp, dashboard_app, DASHBOARD, APP,
    GtkApplication);

DashboardApp *dashboard_app_new (void);

#endif

