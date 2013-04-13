--- openbox/event.c.orig	2011-08-02 05:14:58.000000000 +0900
+++ openbox/event.c	2013-04-13 10:10:40.000000000 +0900
@@ -1488,7 +1488,8 @@
             }
             else if ((Atom)e->xclient.data.l[2] ==
                      OBT_PROP_ATOM(NET_WM_MOVERESIZE_CANCEL))
-                moveresize_end(TRUE);
+                if (moveresize_client)
+                    moveresize_end(TRUE);
         } else if (msgtype == OBT_PROP_ATOM(NET_MOVERESIZE_WINDOW)) {
             gint ograv, x, y, w, h;
 
