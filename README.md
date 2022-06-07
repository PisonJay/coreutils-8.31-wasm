If you downloaded your own wasi-sdk, set `$WASI_PREFIX` to where it's installed before building, e.g. `$HOME/wasi-sdk-16.0`.
If `$WASI_PREFIX` not set, the scripts use `$WASI_PREFIX=/usr` by default.


For a clean build, run commands below

```bash
source wasm-env && ./configure --disable-nls --host=wasm32
make build-sources
./wasm-compile
```

Now `base64.wasm`, `uniq.wasm`, `md5sum.wasm` should be ready for use.


If encountered error like `aclocal not found`, try refresh file timestamp with

```bash
find . -type f -exec touch {}
```
and then make again.
