<?php

function _compressDirectoryToTar($dir_name){
    
    if($dir_name != NULL){
    
        $dir_name = file_stream_wrapper_get_instance_by_uri($dir_name)->realpath();
        $tar_ext  = '.tar';
        $tarFile  = $dir_name . $tar_ext;
        
        try {
        
            if(file_exists($tarFile)){
                @unlink($tarFile);
            }
        
            $a = new PharData($tarFile);
            $a->buildFromDirectory($dir_name);
            
            return $dir_name;
        
        } catch (Exception $e) {
            
            drupal_set_message(t('Erreur de compression de dossier'), 'error');
        }
        
    }
    
    return NULL;
}