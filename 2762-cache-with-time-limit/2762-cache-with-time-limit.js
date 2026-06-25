var TimeLimitedCache = function() {
    // Locker room: Ek Map banaya jahan saare keys store honge
    this.cache = new Map(); 
};

/** * @param {number} key
 * @param {number} value
 * @param {number} duration
 * @return {boolean}
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    // 1. Check karo kya yeh key pehle se locker me active hai?
    const hasKey = this.cache.has(key);
    
    // 2. Agar pehle se active thi, toh purana bomb (timer) defuse (clear) karo
    if (hasKey) {
        clearTimeout(this.cache.get(key).timerId);
    }
    
    // 3. Naya bomb (timer) lagao jo 'duration' ke baad is key ko delete kar dega
    const timerId = setTimeout(() => {
        this.cache.delete(key);
    }, duration);
    
    // 4. Locker me naya saaman aur naya timerId daal do
    this.cache.set(key, { value, timerId });
    
    // 5. Purani key maujood thi toh true, nahi toh false
    return hasKey;
};

/** * @param {number} key
 * @return {number}
 */
TimeLimitedCache.prototype.get = function(key) {
    // Agar locker me key hai, toh value do, nahi toh -1 do
    if (this.cache.has(key)) {
        return this.cache.get(key).value;
    }
    return -1;
};

/** * @return {number}
 */
TimeLimitedCache.prototype.count = function() {
    // Map ka size hi active (un-expired) keys ka count hai
    return this.cache.size;
};