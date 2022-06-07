

To clean build,

```
source wasm-env && ./configure --disable-nls --host=wasm32
make build-sources
./wasm-compile
```

Now `base64.wasm`, `uniq.wasm`, `md5sum.wasm` should be ready for use.