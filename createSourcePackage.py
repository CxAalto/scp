import sys,os

version="0.1"
libName="scp"
packageName=libName+"_"+version

sourcePath = os.path.dirname(os.path.abspath(__file__))+"/"

sourceFiles=["cliqueHash.cpp",
             "communityTracker.cpp",
             "dendrogram.cpp",
             "k_clique.h",
             "kruskal.h",
             "nodeCommunities.cpp",
             "weighedClique.cpp",
             "cliqueHash.h",
             "communityTracker.h",
             "dendrogram.h",
             "k_clique.cpp",
             "kruskal.cpp",
             "makefile",
             "nodeCommunities.h",
             "testScp.py",
             "weighedClique.h",
             "testData/random_1000_005.edg",
             "testData/random_1000_005.edg_files/k=3/communities",
             "testData/random_1000_005.edg_files/k=4/communities",
             "testData/random_1000_005.edg_files/k=5/communities"]

def createSourceDir(targetRootDir="."):
    os.popen("mkdir "+targetRootDir+"/"+packageName)
    
    #infer the dir structure from the file names
    dirs=set()
    for file in sourceFiles:
        dirlist=file.split("/")[:-1]
        for i in range(1,len(dirlist)+1):
            dirs.add("/".join(dirlist[:i]))
    dirs=list(dirs)
    dirs.sort(key=len)

    #create the dirs
    for dir in dirs:
        os.popen("mkdir "+targetRootDir+"/"+packageName+"/"+dir)
    
    #copy source files:
    for file in sourceFiles:
        outputFile=targetRootDir+"/"+packageName+"/"+file
        inputFile=sourcePath+file
        if file.endswith(".h") or file.endswith(".cpp"):
            os.popen("echo '/*' > "+outputFile)
            os.popen("cat LicenseHeader.txt >> "+outputFile)
            os.popen("echo '*/\n' >> "+outputFile)
            os.popen("sed 's/..\/lcelib/lcelib/g' "+inputFile+" >> "+outputFile) #replace ../lcelib with lcelib
        else:
            os.popen("cat "+inputFile+" > "+outputFile)

    #copy license file
    os.popen("cp "+sourcePath+"License.txt "+targetRootDir+"/"+packageName+"/")


if __name__=="__main__":
    #copy and modify the source files
    createSourceDir()
    
    #include lcelib
    sys.path.insert(0,"../lcelib/")
    import createSourcePackage as lcelib
    lcelib.createSourceDir(targetRootDir=packageName)
    os.popen("mv "+packageName+"/"+lcelib.packageName+" "+packageName+"/lcelib")

    #create the tar package
    os.popen("tar -czf "+packageName+".tar.gz "+packageName+"/*")

    #remove the dir
    os.popen("rm -r "+packageName)
