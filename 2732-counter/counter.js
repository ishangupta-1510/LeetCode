/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let count = n-1;
    return function() {
        return count = count + 1;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */