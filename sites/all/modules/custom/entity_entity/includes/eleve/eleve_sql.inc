<?php


/**
 * alaina ao amin'ny relation eleveTaompianarana ity ka tsy maintsy misy ny class eto
 * @param type $niveau_tid
 * @param type $class_tid
 * @param type $taompianarana_tid
 */
function _eleve_sql_list_eleve($niveau_tid = NULL, $class_tid = NULL,$taompianarana_tid,$nom_prenom = NULL,$num_mat = NULL ,$sex = NULL) {
    
    $sql = "";
    
    if($taompianarana_tid != NULL){
        
        $sql .= "SELECT ";
        $sql .= " num_mat.field_num_mat_value as NUM_MAT,";
        $sql .= " nom.field_nom_value as NOM,";
        $sql .= " prenom.field_prenom_value as PRENOM,";
        $sql .= " sex.field_sex_tid as SEXE_TID,";
        $sql .= " sex_name.name as SEXE,";
        $sql .= " date_naiss.field_date_naiss_value as DATE_NAISS,";
        
        $sql .= " niveau_name.name as NIVEAU_NAME,";
        $sql .= " class_name.name as CLASS_NAME,";
        $sql .= " taompianarana_name.name as TAOMPIANARANA_NAME,";
        $sql .= " e.eleve_id as ID,";
        
        $sql .= " e.niveau_tid as NIVEAU_TID,";
        $sql .= " e.class_tid as CLASS_TID,";        
        $sql .= " e.taompianarana_tid as TAOMPIANARANA_TID";
        
        $sql .= " FROM";
        
        $sql .= " eleveTaompianarana e";
        
        $sql .= " JOIN field_data_field_num_mat num_mat";
        $sql .= " ON  num_mat.entity_id = e.eleve_id";
        $sql .= " AND num_mat.bundle = 'eleve'";
        $sql .= " AND num_mat.entity_type = 'eleve'";
        
        $sql .= " JOIN field_data_field_nom nom";
        $sql .= " ON  nom.entity_id = e.eleve_id";
        $sql .= " AND nom.bundle = 'eleve'";
        $sql .= " AND nom.entity_type = 'eleve'";
        
        $sql .= " JOIN field_data_field_prenom prenom";
        $sql .= " ON  prenom.entity_id = e.eleve_id";
        $sql .= " AND prenom.bundle = 'eleve'";
        $sql .= " AND prenom.entity_type = 'eleve'";
        
        $sql .= " JOIN field_data_field_sex sex";
        $sql .= " ON  sex.entity_id = e.eleve_id";
        $sql .= " AND sex.bundle = 'eleve'";
        $sql .= " AND sex.entity_type = 'eleve'";

        $sql .= " JOIN taxonomy_term_data sex_name";
        $sql .= " ON  sex_name.tid = sex.field_sex_tid";

        $sql .= " JOIN field_data_field_date_naiss date_naiss";
        $sql .= " ON  date_naiss.entity_id = e.eleve_id";
        $sql .= " AND date_naiss.bundle = 'eleve'";
        $sql .= " AND date_naiss.entity_type = 'eleve'";
        
        $sql .= " JOIN taxonomy_term_data niveau_name";
        $sql .= " ON  niveau_name.tid = e.niveau_tid";
        
        $sql .= " JOIN taxonomy_term_data class_name";
        $sql .= " ON  class_name.tid = e.class_tid";
        
        $sql .= " JOIN taxonomy_term_data taompianarana_name";
        $sql .= " ON  taompianarana_name.tid = e.taompianarana_tid";
        
        $sql .= " WHERE e.taompianarana_tid = ".$taompianarana_tid;
        if($niveau_tid != NULL){
            $sql .= " AND e.niveau_tid IN (".$niveau_tid.")";
        }
        if($class_tid != NULL){
            $sql .= " AND e.class_tid IN (".$class_tid.")";
        }
        if($nom_prenom != NULL){
            $sql .= " AND (nom.field_nom_value LIKE '%".$nom_prenom."%' OR prenom.field_prenom_value LIKE '%".$nom_prenom."%')";
        }
        if($num_mat != NULL){
            $sql .= " AND num_mat.field_num_mat_value LIKE '".$num_mat."%'";
        }
        if($sex != NULL){
            $sql .= " AND sex.field_sex_tid IN (".$sex.")";
        }
    }
    
    return $sql;
    
}

/**
 * SQL maka ny eleve par num_matricule
 * 
 * @param type $string
 * @param type $operator
 * @return string
 */
function _eleve_sql_get_by_num_mat($string, $operator = 'LIKE') {
    
    $query = "SELECT ";
    $query .= " e.id as ID, num_mat.field_num_mat_value as NUM_MAT ";
    $query .= " FROM eck_eleve e";
    $query .= " JOIN field_data_field_num_mat num_mat";
    $query .= " ON  num_mat.entity_id    = e.id";
    $query .= " AND num_mat.bundle       = 'eleve'";
    $query .= " AND num_mat.entity_type  = 'eleve'";
    $query .= " WHERE num_mat.field_num_mat_value ";
    $query .= $operator."'".$string;
    if($operator == 'LIKE'){
        $query .= "%'";
    }else{
        $query .= "'";
    }
    
    return $query;
}

/**
 * SQL maka ny eleve par num_matricule
 * 
 * @param type $string
 * @param type $operator
 * @return string
 */
function _eleve_sql_get_by_id($id) {
    $query = "";
    if($id != NULL){

        $query = "SELECT ";
        $query .= " e.id as ID, num_mat.field_num_mat_value as NUM_MAT ";
        $query .= " FROM eck_eleve e";
        $query .= " JOIN field_data_field_num_mat num_mat";
        $query .= " ON  num_mat.entity_id    = e.id";
        $query .= " AND num_mat.bundle       = 'eleve'";
        $query .= " AND num_mat.entity_type  = 'eleve'";
        $query .= " WHERE e.id =".$id;
    }
    return $query;
}

/**
 * 
 * Maka ny ankizy iray par rapport amin'ny taompianarana ity
 * 
 * @param type $eleve_id
 * @param type $taompianarana
 * @return string
 */
function _look_up_eleve_in_eleve_taompianarana_sql($eleve_id ,$taompianarana = NULL) {
    
    $sql = "";
    
    if($taompianarana == NULL){
        $taompianarana = variable_get('TAOMPIANARANA');
    }
    if($eleve_id != NULL){
        
        $sql .= "SELECT";
        
        $sql .= " e.eleve_id as ELEVE_ID, e.taompianarana_tid as TAOMPIANARANA_TID,";
        $sql .= " e.niveau_tid as NIVEAU_TID, e.class_tid as CLASS_TID,";
        $sql .= " e.id as ID";
                
        $sql .= " FROM";
        
        $sql .= " eleveTaompianarana e";
        
        $sql .= " WHERE e.eleve_id =".$eleve_id;
        $sql .= " AND   e.taompianarana_tid =".$taompianarana;
        
    }
    
    return $sql;
}


/**
 * 
 * Maka ny eleve rehetra tsy manan class ity
 * 
 * @param type $niveau_tid
 * @param type $class_tid
 * @param type $taompianarana_tid
 * @return string
 */
function _eleve_sql_list_eleve_no_class($niveau_tid = NULL) {
    
    $sql = "";
    
    $sql .= "SELECT ";
    $sql .= " num_mat.field_num_mat_value as NUM_MAT,";
    $sql .= " nom.field_nom_value as NOM,";
    $sql .= " prenom.field_prenom_value as PRENOM,";
    $sql .= " sex_name.name as SEXE,";
    $sql .= " sex.field_sex_tid as SEXE_TID,";
    $sql .= " date_naiss.field_date_naiss_value as DATE_NAISS,";
    $sql .= " e.eleve_id as ID,";

    $sql .= " niveau_name.name as NIVEAU_NAME,";
    $sql .= " taompianarana_name.name as TAOMPIANARANA_NAME,";

    $sql .= " e.niveau_tid as NIVEAU_TID,";
    $sql .= " e.taompianarana_tid as TAOMPIANARANA_TID";

    $sql .= " FROM";

    $sql .= " eleveTaompianarana e";

    $sql .= " JOIN field_data_field_num_mat num_mat";
    $sql .= " ON  num_mat.entity_id = e.eleve_id";
    $sql .= " AND num_mat.bundle = 'eleve'";
    $sql .= " AND num_mat.entity_type = 'eleve'";

    $sql .= " JOIN field_data_field_nom nom";
    $sql .= " ON  nom.entity_id = e.eleve_id";
    $sql .= " AND nom.bundle = 'eleve'";
    $sql .= " AND nom.entity_type = 'eleve'";

    $sql .= " JOIN field_data_field_prenom prenom";
    $sql .= " ON  prenom.entity_id = e.eleve_id";
    $sql .= " AND prenom.bundle = 'eleve'";
    $sql .= " AND prenom.entity_type = 'eleve'";

    $sql .= " JOIN field_data_field_sex sex";
    $sql .= " ON  sex.entity_id = e.eleve_id";
    $sql .= " AND sex.bundle = 'eleve'";
    $sql .= " AND sex.entity_type = 'eleve'";

    $sql .= " JOIN taxonomy_term_data sex_name";
    $sql .= " ON  sex_name.tid = sex.field_sex_tid";

    $sql .= " JOIN field_data_field_date_naiss date_naiss";
    $sql .= " ON  date_naiss.entity_id = e.eleve_id";
    $sql .= " AND date_naiss.bundle = 'eleve'";
    $sql .= " AND date_naiss.entity_type = 'eleve'";

    $sql .= " JOIN taxonomy_term_data niveau_name";
    $sql .= " ON  niveau_name.tid = e.niveau_tid";

    $sql .= " JOIN taxonomy_term_data taompianarana_name";
    $sql .= " ON  taompianarana_name.tid = e.taompianarana_tid";

    $sql .= " WHERE e.taompianarana_tid = ".  variable_get('TAOMPIANARANA');
    $sql .= " AND e.class_tid IS NULL";
    
    if($niveau_tid != NULL){
        $sql .= " AND e.niveau_tid IN (".$niveau_tid.")";
    }
    
    return $sql;
    
}


/*
 * 
 * Maka ny eleve rehetra tsy manan class ity
 * 
 * @param type $niveau_tid
 * @param type $class_tid
 * @param type $taompianarana_tid
 * @return string
 */
function _eleve_sql_list_eleve_by_niveau($niveau_tid = NULL) {
    
    $sql = "";
    
    $sql .= "SELECT ";
    $sql .= " num_mat.field_num_mat_value as NUM_MAT,";
    $sql .= " nom.field_nom_value as NOM,";
    $sql .= " prenom.field_prenom_value as PRENOM,";
    $sql .= " sex_name.name as SEXE,";
    $sql .= " sex.field_sex_tid as SEXE_TID,";
    $sql .= " date_naiss.field_date_naiss_value as DATE_NAISS,";
    $sql .= " e.eleve_id as ID,";

    $sql .= " niveau_name.name as NIVEAU_NAME,";
    $sql .= " taompianarana_name.name as TAOMPIANARANA_NAME,";

    $sql .= " e.niveau_tid as NIVEAU_TID,";
    $sql .= " e.taompianarana_tid as TAOMPIANARANA_TID";

    $sql .= " FROM";

    $sql .= " eleveTaompianarana e";

    $sql .= " JOIN field_data_field_num_mat num_mat";
    $sql .= " ON  num_mat.entity_id = e.eleve_id";
    $sql .= " AND num_mat.bundle = 'eleve'";
    $sql .= " AND num_mat.entity_type = 'eleve'";

    $sql .= " JOIN field_data_field_nom nom";
    $sql .= " ON  nom.entity_id = e.eleve_id";
    $sql .= " AND nom.bundle = 'eleve'";
    $sql .= " AND nom.entity_type = 'eleve'";

    $sql .= " JOIN field_data_field_prenom prenom";
    $sql .= " ON  prenom.entity_id = e.eleve_id";
    $sql .= " AND prenom.bundle = 'eleve'";
    $sql .= " AND prenom.entity_type = 'eleve'";

    $sql .= " JOIN field_data_field_sex sex";
    $sql .= " ON  sex.entity_id = e.eleve_id";
    $sql .= " AND sex.bundle = 'eleve'";
    $sql .= " AND sex.entity_type = 'eleve'";

    $sql .= " JOIN taxonomy_term_data sex_name";
    $sql .= " ON  sex_name.tid = sex.field_sex_tid";

    $sql .= " JOIN field_data_field_date_naiss date_naiss";
    $sql .= " ON  date_naiss.entity_id = e.eleve_id";
    $sql .= " AND date_naiss.bundle = 'eleve'";
    $sql .= " AND date_naiss.entity_type = 'eleve'";

    $sql .= " JOIN taxonomy_term_data niveau_name";
    $sql .= " ON  niveau_name.tid = e.niveau_tid";

    $sql .= " JOIN taxonomy_term_data taompianarana_name";
    $sql .= " ON  taompianarana_name.tid = e.taompianarana_tid";

    $sql .= " WHERE e.taompianarana_tid = ".  variable_get('TAOMPIANARANA');
    
    if($niveau_tid != NULL){
        $sql .= " AND e.niveau_tid IN (".$niveau_tid.")";
    }
    
    return $sql;
    
}
