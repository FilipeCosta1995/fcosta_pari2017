/**
 *       @file  
 *      @brief  Breve Descrição
 *
 * Descrição mais detalhada do ficheiro que até poderiam incluir links para imagens etc.
 *
 *     @author  Filipe Costa, costa.filipe@ua.pt
 *
 *   @internal
 *     Created  22-Nov-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Filipe Costa
 *
 * =====================================================================================
 */

#include "myf.h"

/**
 * @brief  Callback to process the delete_event (usually, window kill request)
 *
 * @param  window - The widget that generated the event (not used here)
 * @param  event - The event description (not used here)
 * @param  data - generic user data (not used here)
 * @return FALSE - destroy window but does not leave gtk_main loop, and generates a "destroy" event that you can intersect with another callback.
 * @return TRUE - ignore this delete_event request and does nothing. This can be used to give a second chance to user before closing window!
 * The same effect of <b>TRUE</b> is obtained by returning no value, that is using a <b>void</b> type of function.
 */
void pari_delete_event(GtkWidget * window, GdkEvent * event, gpointer data) //static gboolean
{
        puts("Pedido de delete event");
	
	g_print("You should not use the OS to force leave!\n");
	gtk_main_quit();
        //return FALSE; //destroy window but does not leave gtk_main loop, and generates a "destroy" event
        //return TRUE; //ignore this delete_event request and does nothing. Same effect as returning 'void'
}
/**
 * @brief  Callback to process the "destroy" event
 *
 * Here you can decide whether you keep in the gtk_main loop operation or if you terminate it
 * That is, you can decide to continue with the GUI running or close the GUI, but not necessarily the application
 * Stop the GTK+ main loop function when the window is destroyed.
 * This event only occurs if delete_event returns FALSE
 * @param  window - The widget that generated the event (not used here)
 * @param  data - generic user data (not used here)
 * @return void
 */
/*
static void pari_destroy(GtkWidget * window, gpointer data)
{
        puts("Pedido de destruição de janela");
        //gtk_main_quit();  //necessary to to leave GTK main loop
}
*/


/**
 * @brief  Callback to catch CTRL-C
 */
void InterceptCTRL_C(int a)
{
  g_print("Sair por CTRL-C\n");
  gtk_main_quit();
}




/**
 * @brief  Manage button 3 click with the intention to leave application
 *    Either shows a message or exits
 *
 * @param  w - The Widget ID
 * @param user_data - Custom data with the ID of another widget to check. In this case the switch1
 * @return void
 */
void on_button2_clicked(GtkWidget * widget, gpointer user_data)
{
  gboolean a=gtk_switch_get_active( GTK_SWITCH(user_data) );//user_data point to switch
  if (a == FALSE)
        printf("Must enable the Quit switch before leaving\n");
  else
        gtk_main_quit();
}

/**
 * @brief  Function to process the text from entry and label
 *
 * @param widget - the one that originated the call
 * @param user_data - Custom data with a widget ID to fetch some info
 * @return void
 */
#if 1

void on_button1_clicked(GtkWidget *widget, gpointer user_data)
{
  GtkEntry *ts = GTK_ENTRY(user_data);
  GtkLabel *lbl= GTK_LABEL(gtk_builder_get_object(builderG,"label3")); //Get some specific label ID to change it
  if(ts)
  {
        const char* tss = gtk_entry_get_text(ts); //get the text from entry1 widget
	ReverseString((char*)tss);
        printf("Text available in entry1: %s\n", tss);
        gtk_label_set_text(lbl, tss);   //set entry text in "label2" widget
	//gtk_entry_set_text(ts, tss);
	gtk_widget_hide(GTK_WIDGET(ts));
	gtk_widget_show(GTK_WIDGET(ts));	
  }
}
#endif



/**
 * @brief  
 * @param  
 * @return 
 */

void ReverseString(char *str)
{
  char c, *t1, *t2;
  for(t1 = str, t2 = str + strlen(str); t1 < t2;) //notice that 3rd param of for is empty
      c = *t1, *t1++ = *--t2, *t2 = c;
}
