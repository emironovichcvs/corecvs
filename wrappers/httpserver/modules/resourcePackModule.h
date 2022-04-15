#ifndef RESOURCEPACKMODULE_H
#define RESOURCEPACKMODULE_H

#include <httpUtils.h>
#include <memory.h>

#include "httpServerModule.h"
#include "compiledResourceDirectory.h"

class ResourcePackContent : public HttpContent
{
public:
    CompiledResourceDirectoryEntry *data;

    ResourcePackContent(CompiledResourceDirectoryEntry *data) :
        data(data)
    {}

    virtual std::vector<uint8_t> getContent() override
    {
        std::vector<uint8_t> result;
        result.resize(data->length);
        memcpy(result.data(), data->data, data->length);
        return result;
    }

    virtual std::string getContentType() override
    {
        return HttpUtils::extentionToMIME(data->name);
    }
};

class ResourcePackModule : public HttpServerModule
{
public:
    /* Build a set here for fast search. I'm too lazy for this */
    CompiledResourceDirectoryEntry *data = NULL;
    int size;

    virtual bool shouldProcessURL(std::string url);
    virtual bool shouldWrapURL(std::string url);
    virtual std::shared_ptr<HttpContent> getContentByUrl(std::string url);


    ResourcePackModule(CompiledResourceDirectoryEntry *data, int size);
};

#endif // RESOURCEPACKMODULE_H