function containsDuplicate(nums: number[]): boolean {
    const map = new Map()
    for(let num of nums){
        if(map.get(num) !== undefined){
            return true
        }
        map.set(num,1)
    }
    return false
};