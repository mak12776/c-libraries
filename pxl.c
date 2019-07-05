
#include <stdlib.h>
#include <string.h>

#include "pxl.h"
#include "error.h"

image *
new_image_mode_size_colors(
	const char *	mode,
	vector_2d_t	size,
	void*		colors,
	error_t	*	error
	)
{
    image *result;

    result = (image *)malloc(sizeof(image));
    if (result == NULL)
    {
	error->num = ERROR_NO_MEMORY;
	set_error_msg(error, 
		INFO "can't allocate memory for image structure");

	return NULL;
    }

    if (strcmp("RGBA", mode) == 0)
    {
	result->buffer = (void *)malloc(sizeof(color_rgba_t) * size.x * size.y);
	if (result->buffer == NULL)
	{
	    error->num = ERROR_NO_MEMORY;
	    set_error_msg(error, 
		    INFO "can't allocate memory for image buffer");

	    free(result);
	    return NULL;
	}

	result->size.x = size.x;
	result->size.y = size.y;

	result->mode = IMAGE_MODE_RGBA;
	result->colors = NULL;

	return result;
    }
    else
    {
	error->num = ERROR_INVALID_ARGUMENTS;
	set_error_msg(error, INFO "invalid argument for mode");

	return NULL;
    }
}

#if 0
void
image_draw_hline(image *img, unit_t x0, unit_t x1, uint_t y, void *color)
{
    if (image->mode == IMAGE_MODE_RGBA)
    {
	
    }
}

void
image_draw_vline(image *img, unit_t x, unit_t y0, unit_t y1, void *color)
{

}
#endif

