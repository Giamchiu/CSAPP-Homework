long decode2(long x, long y, long z){
    long rval=y-z;
    return ((rval<<63)>>63)^(rval*x);
}