// Solution 1
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    if (path === "/" || path === '/./' || path === "/../") return '/';
    const directories = [];
    let folder = '';
    for (let i = 0; i <= path.length; i++) {
        if (i === path.length || path[i] === '/') {
            if (folder.length === 0) continue;
            if (folder === '..') {
                directories.pop();
            } else if (folder !== '.') directories.push(folder);
            folder = '';
            continue;
        }
        else {
            folder += path[i];
        }
    }

    let final = '';
    for (let i = 0; i < directories.length; i++) {
        final += `/${directories[i]}`
    }

    return final.length > 0 ? final : '/';
};


// Solution 2
var simplifyPath = function(path) {
    const tokens = path.split('/');
    const newPath = [];
    for (const token of tokens) {
        if (token === '..') {
            newPath.pop();
        } else if (token !== '' && token !== '.') {
            newPath.push(token);
        }
    }
    return '/' + newPath.join('/');
};
