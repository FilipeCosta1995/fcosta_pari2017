/**
 *       @file  hello.c
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

#define _MAIN_C_

#include "myf.h"

int main(int argc, char *argv[])
{
        gtk_init(&argc, &argv);

        /* load the interface after a configuration file*/
        builderG = gtk_builder_new();
        gtk_builder_add_from_file(builderG, "exp.glade", NULL);

        /* connect the signals in the interface */
        gtk_builder_connect_signals(builderG, NULL);
							//obrigatorio^
        /* get main window Widget ID and connect special signals */
        GtkWidget *t = GTK_WIDGET(gtk_builder_get_object(builderG, "window1"));
        
	if(t)
        {
                g_signal_connect(G_OBJECT(t), "delete_event", G_CALLBACK(pari_delete_event), NULL);
        }

        // use signal to catch SIGINT  (CTRL-C) - optional
        signal(SIGINT, InterceptCTRL_C);

	p_InitTimer();

        /* start the event loop */
        gtk_main();

        return 0;
}

