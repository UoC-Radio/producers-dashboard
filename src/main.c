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

#include "dashboard-app.h"
#include <gtk/gtk.h>

gint
main (gint argc, gchar *argv[])
{
  g_autoptr (DashboardApp) app;

  app = dashboard_app_new ();
  return g_application_run (G_APPLICATION (app), argc, argv);
}
