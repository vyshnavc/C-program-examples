#include<gst/gst.h>
#include<stdio.h>

void main(int argc, char *argv)
{

GstElement *pipeline;
GstBus *bus;
GstMessage *msg;


gst_init (&argc, &argv);


pipeline = gst_parse_launch("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
              NULL);

gst_element_set_state(pipeline,GST_STATE_PLAYING);
bus = gst_element_get_bus(pipeline);
msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
              GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* See next tutorial for proper error message handling/parsing */
  if (GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR) {
          g_error ("An error occurred! Re-run with the GST_DEBUG=*:WARN environment "
                          "variable set for more details.");
            }


gst_object_unref(bus);
gst_message_unref(msg);
gst_element_set_state(pipeline,GST_STATE_NULL);
gst_object_unref(pipeline);


}
