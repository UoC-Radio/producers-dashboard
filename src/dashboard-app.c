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

struct _DashboardApp
{
  GtkApplication parent;
};

G_DEFINE_TYPE (DashboardApp, dashboard_app, GTK_TYPE_APPLICATION);

static void
dashboard_app_load_main_window (DashboardApp *self)
{
  g_autoptr (GtkBuilder) builder = NULL;
  GtkWindow *window;

  builder = gtk_builder_new_from_resource (
      "/gr/uoc/radio/dashboard/main_window.ui");
  window = GTK_WINDOW (gtk_builder_get_object (builder, "mainwindow"));
  gtk_application_add_window (GTK_APPLICATION (self), window);
  gtk_widget_show_all (GTK_WIDGET (window));
}

static void
dashboard_app_activate (GApplication *app)
{
  DashboardApp *self = DASHBOARD_APP (app);
  GtkWindow *window;

  window = gtk_application_get_active_window (GTK_APPLICATION (self));
  if (!window)
    dashboard_app_load_main_window (self);
  /* else hint the WM to focus the window - TODO need to find how to do that */

  G_APPLICATION_CLASS (dashboard_app_parent_class)->activate (app);
}

static void
dashboard_app_class_init (DashboardAppClass *klass)
{
  GApplicationClass *gapp_class = (GApplicationClass *) klass;

  gapp_class->activate = dashboard_app_activate;
}

static void
dashboard_app_init (DashboardApp *self)
{
}

DashboardApp *
dashboard_app_new (void)
{
  return DASHBOARD_APP (g_object_new (DASHBOARD_TYPE_APP,
      "application-id", "gr.uoc.radio.dashboard",
      "flags", G_APPLICATION_FLAGS_NONE,
      NULL));
}

