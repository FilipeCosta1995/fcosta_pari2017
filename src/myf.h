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

#include <gtk/gtk.h>
#include <string.h>
#include <cairo.h>

#define MAXFFBUFFER 10000
typedef struct {
  int count;
  double x[MAXFFBUFFER];
  double y[MAXFFBUFFER];
} free_form;


#ifdef _MAIN_C_
	GtkBuilder *builderG;
	double xoffG=100;
	double yoffG=120;
	free_form ffG={0};   //init count to zero. Do not affect x and y.
	double fontSizeFactorG=1;

#else
	extern GtkBuilder *builderG;
	extern double xoffG;
	extern double yoffG;
	extern free_form ffG;
	extern double fontSizeFactorG;
#endif

#include "prototypes.h"
