/**
 * @param {Function} fn
 * @return {Function}
 */
/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  /* Solution: I use nested Map objects (chains of Map objects) to store
  values. For example, the value for arguments 1,2,3 would be found in
  1->2->3->special-key->value. A special key is used to store the final
  value, so we can store a value also for, say, arguments 1,2,3,4. As a
  special key we are using an object we create ourselves (so nobody else
  has that reference), so we know no arguments can be equal (===) to
  it. (Remember that js Maps use === for equality.)*/
  let mem = new Map();
  let myKey = {gp: "key"};

  // insert (K&R use the term 'install'...)
  function install(keys, val) {
    let memC = mem;
    for (let i = 0; i < keys.length; i++) {
      let key = keys[i];
      let next = memC.get(key); // either a map or undefined
      if (!next) {
        next = new Map();
        memC.set(key, next);
      }
      memC = next;
    }
    return memC.set(myKey, val); 
  }

  function lookup(keys) {
    let memC = mem; 
    for (let i = 0; i < keys.length; i++) {
      let key = keys[i];
      if (memC.has(key)) {
        memC = memC.get(key);
      } else {
        return {found: false};
      }
    }
    return memC.has(myKey) ? {found: true, val: memC.get(myKey)} : {found: false};  
  }
    
  return function() {
    let found = lookup(arguments);
    if (found.found) return found.val;

    const res = fn.apply(null, arguments);

    install(arguments, res);
    return res;
  }
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
