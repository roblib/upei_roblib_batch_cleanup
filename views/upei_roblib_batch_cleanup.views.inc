<?php

/**
 * @file
 *  Alter some islandora_batch default views.
 */

/**
 * Implements hook_views_default_views().
 */
function upei_roblib_batch_cleanup_views_default_views_alter(&$views) {
  // sites will choke if you try to load the display of a view that does not exist
  // so we check to see if the view exists before trying to alter it.
    if (array_key_exists('islandora_batch_sets', $views)) {
      $handler =& $views['islandora_batch_sets']->display['default']->handler;
      /* No results behavior: Global: Text area */
      $handler->display->display_options['footer']['area']['id'] = 'area';
      $handler->display->display_options['footer']['area']['table'] = 'views';
      $handler->display->display_options['footer']['area']['field'] = 'area';
      $handler->display->display_options['footer']['area']['empty'] = TRUE;
      $handler->display->display_options['footer']['area']['content'] = 'Completed sets will automatically be deleted if they are older then a week.';
      $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
    }
}