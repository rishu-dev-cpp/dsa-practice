/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timerId = null; // Dukandar ka timer token
    
    return function(...args) {
        // 1. Agar pehle se koi timer chal raha hai, toh use turant cancel (clear) karo
        if (timerId) {
            clearTimeout(timerId);
        }
        
        // 2. Naye sire se 't' milliseconds ka naya timer shuru karo
        timerId = setTimeout(() => {
            fn(...args); // Jab bina ruke 't' time beet jaye, tab asli function chalao
        }, t);
    };
};