const path = require('path')
const fs = require('fs')
const { exec, execSync, spawn } = require('child_process');

/**
 * 
 * @param {string} command 
 * @returns {Promise<string>}
 */
function run(command){
    return new Promise((res,rej)=>{
        exec(command,(err,result,errStr)=>{
            if(err){
                rej(errStr)
            }
            else
            {
                res(result)
            }
        })
    })
}

/**
 * 
 * @param {string} command 
 * @returns {Promise<string>}
 */
function runAndDisplay(command){
    return new Promise((res,rej)=>{
       const childProcess = exec(command,(err,result,errStr)=>{
            if(err){
                rej(errStr)
            }
            else
            {
                res(result)
            }
        })
        childProcess.stdout.pipe(process.stdout)
        childProcess.stderr.pipe(process.stderr)
    })
}

async function main(){
    const ghVersion = await run('git tag --sort=committerdate').then(c => c.trim().split('\n').reverse()[0].trim().slice(1));

    const packageJson = await fs.promises.readFile(path.join(process.cwd(),'package.json'),'utf-8').then(c => JSON.parse(c));
    const packageJsonVersion = packageJson['version'];

    if(ghVersion === packageJsonVersion){
        console.log("Cancelling build")
    }
    else
    {
        await fs.promises.writeFile("build.file","\n\n")
        console.log("Building")
    }
}

main()