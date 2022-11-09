# Inspired by https://github.com/okdistribute/jsonschema-protobuf

> Basically it's just a dummy fork

How to use:

```bash
> npm i protocol-buffers-schema

> mkdir build

> node cli.js schema.json > build/model.proto
# or
> ./cli.js schema.json > build/model.proto

> protoc build/model.proto --cpp_out=.
```

## Not possible to fully use proto3

Example, create required field

```protobuf
oneof req_type {
    uint32 req = 1;
}
```

## Cannot specify types like uint8_t

It's possible to use it in such generator, but not supported by original json schema specs
