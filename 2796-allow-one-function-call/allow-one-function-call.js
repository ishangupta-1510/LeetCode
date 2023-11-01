/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let con = 1;
	return function(...args){
        if(con === 1){
            con = 0;
            return fn(...args);
        }
        else{
            return undefined;
        }
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
