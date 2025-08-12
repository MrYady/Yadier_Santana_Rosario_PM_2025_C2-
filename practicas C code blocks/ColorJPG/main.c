#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>

void invert_colors(JSAMPARRAY buffer, int width) {
    for (int i = 0; i < width * 3; i++) {
        buffer[0][i] = 255 - buffer[0][i];  // Invertir R, G o B
    }
}

int main() {
    FILE *input = fopen("input.jpg", "rb");
    FILE *output = fopen("output.jpg", "wb");

    if (!input || !output) {
        perror("Error abriendo archivos");
        return 1;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_compress_struct cinfo_out;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, input);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    // Preparar salida
    cinfo_out.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo_out);
    jpeg_stdio_dest(&cinfo_out, output);

    cinfo_out.image_width = cinfo.output_width;
    cinfo_out.image_height = cinfo.output_height;
    cinfo_out.input_components = cinfo.output_components;
    cinfo_out.in_color_space = cinfo.out_color_space;

    jpeg_set_defaults(&cinfo_out);
    jpeg_start_compress(&cinfo_out, TRUE);

    JSAMPARRAY buffer = (*cinfo.mem->alloc_sarray)
        ((j_common_ptr)&cinfo, JPOOL_IMAGE, cinfo.output_width * cinfo.output_components, 1);

    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, buffer, 1);
        invert_colors(buffer, cinfo.output_width);
        jpeg_write_scanlines(&cinfo_out, buffer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    jpeg_finish_compress(&cinfo_out);
    jpeg_destroy_compress(&cinfo_out);

    fclose(input);
    fclose(output);

    printf("Imagen procesada y guardada como output.jpg\n");
    return 0;
}

