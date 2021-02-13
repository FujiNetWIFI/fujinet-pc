#ifndef HTTPSERVICEBROWSER_H
#define HTTPSERVICEBROWSER_H

#include "fnFS.h"

extern "C"
{
#include "mongoose.h"
}

class fnHttpServiceBrowser
{
    static int browse_url_encode(const char *src, size_t src_len, char *dst, size_t dst_len);
    static int browse_html_escape(const char *src, size_t src_len, char *dst, size_t dst_len);

    static int browse_listdir(mg_connection *c, FileSystem *pFS, int slot, const char *host_path, unsigned pathlen);
    static int browse_printnavi(mg_connection *c, int slot, char *esc_path, char*enc_path);
    static void browse_printdentry(mg_connection *c, fsdir_entry *dp, int slot, const char *enc_path);

    static int browse_sendfile(mg_connection *c, FileSystem *fs, FileHandler *fh, const char *filename, unsigned long filesize);

public:
    static int process_browse_get(mg_connection *c, int host_slot, const char *host_path, unsigned pathlen);
};

#endif // HTTPSERVICEBROWSER_H
